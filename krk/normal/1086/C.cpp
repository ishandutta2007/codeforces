#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
const int Maxk = 26;

char tmp[Maxn];
int t;
int k;
bool tk[Maxk];
bool mytk[Maxk];
int seq[Maxk];
int myseq[Maxk];
string S, A, B, R;

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

void getGreatest(int lvl)
{
    for (int i = 0; i < k; i++) {
        myseq[i] = seq[i];
        mytk[i] = tk[i];
    }
    int pnt = k - 1;
    for (int i = lvl; i < S.length(); i++) {
        int let = S[i] - 'a';
        if (myseq[let] == -1) {
            while (mytk[pnt]) pnt--;
            myseq[let] = pnt; mytk[pnt] = true;
        }
    }
    for (int i = 0; i < k; i++)
        if (myseq[i] == -1) {
            while (mytk[pnt]) pnt--;
            myseq[i] = pnt; mytk[pnt] = true;
        }
}

void getSmallest(int lvl)
{
    for (int i = 0; i < k; i++) {
        myseq[i] = seq[i];
        mytk[i] = tk[i];
    }
    int pnt = 0;
    for (int i = lvl; i < S.length(); i++) {
        int let = S[i] - 'a';
        if (myseq[let] == -1) {
            while (mytk[pnt]) pnt++;
            myseq[let] = pnt; mytk[pnt] = true;
        }
    }
    for (int i = 0; i < k; i++)
        if (myseq[i] == -1) {
            while (mytk[pnt]) pnt++;
            myseq[i] = pnt; mytk[pnt] = true;
        }
}

bool Check(int seq[])
{
    R.resize(S.length());
    for (int i = 0; i < S.length(); i++)
        R[i] = seq[S[i] - 'a'] + 'a';
    return A <= R && R <= B;
}

void Print(int seq[])
{
    printf("YES\n");
    for (int i = 0; i < k; i++)
        printf("%c", seq[i] + 'a');
    printf("\n");
}

void printNo() { printf("NO\n"); }

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &k);
        fill(tk, tk + k, false);
        fill(seq, seq + k, -1);
        Read(S); Read(A); Read(B);
        bool ok = true;
        for (int lvl = 0; lvl < S.length(); lvl++) {
            int let = S[lvl] - 'a';
            ok = false;
            int alet = A[lvl] - 'a';
            int blet = B[lvl] - 'a';
            bool tobreak = false;
            for (int i = alet; i <= blet; i++) if (seq[let] == i || !tk[i] && seq[let] == -1) {
                bool upd = seq[let] == -1;
                if (upd) { seq[let] = i; tk[i] = true; }
                if (i == alet && i == blet) { ok = true; break; }
                if (i == alet) {
                    getGreatest(lvl + 1);
                    if (Check(myseq)) { Print(myseq); tobreak = true; break; }
                }
                if (i == blet) {
                    getSmallest(lvl + 1);
                    if (Check(myseq)) { Print(myseq); tobreak = true; break; }
                }
                if (alet < i && i < blet) {
                    getSmallest(lvl + 1);
                    if (Check(myseq)) { Print(myseq); tobreak = true; break; }
                }
                if (upd) { seq[let] = -1; tk[i] = false; }
            }
            if (tobreak) break;
            if (!ok) { printNo(); break; }
        }
        if (ok) {
            getSmallest(S.length());
            if (Check(myseq)) Print(myseq);
            else printNo();
        }
    }
    return 0;
}