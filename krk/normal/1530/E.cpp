#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxl = 26;

int T;
char str[Maxn];
int slen;
int freq[Maxl];
char res[Maxn];
int rlen;

void Print()
{
    res[rlen] = '\0';
    printf("%s\n", res);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        slen = strlen(str);
        fill(freq, freq + Maxl, 0);
        for (int i = 0; i < slen; i++)
            freq[str[i] - 'a']++;
        int all = -1;
        for (int i = 0; i < Maxl; i++)
            if (freq[i] == slen) { all = i; break; }
        if (all != -1) {
            printf("%s\n", string(slen, 'a' + all).c_str());
            continue;
        }
        rlen = 0;
        int fir = -1;
        for (int i = 0; i < Maxl; i++)
            if (freq[i] == 1) { fir = i; break; }
        if (fir != -1) {
            res[rlen++] = 'a' + fir;
            freq[fir]--;
            for (int i = 0; i < Maxl; i++)
                while (freq[i]--)
                    res[rlen++] = 'a' + i;
            Print();
            continue;
        }
        fir = 0;
        while (freq[fir] == 0) fir++;
        if (slen - freq[fir] >= freq[fir] - 2) {
            res[rlen++] = 'a' + fir;
            res[rlen++] = 'a' + fir;
            freq[fir] -= 2;
            for (int i = fir + 1; i < Maxl; i++)
                while (freq[i]--) {
                    res[rlen++] = 'a' + i;
                    if (freq[fir] > 0) {
                        res[rlen++] = 'a' + fir;
                        freq[fir]--;
                    }
                }
            Print();
            continue;
        }
        int sec = fir + 1;
        while (freq[sec] == 0) sec++;
        res[rlen++] = 'a' + fir;
        res[rlen++] = 'a' + sec;
        freq[fir]--;
        freq[sec]--;
        if (freq[fir] + freq[sec] >= slen - 2) {
            while (freq[sec]--)
                res[rlen++] = 'a' + sec;
            while (freq[fir]--)
                res[rlen++] = 'a' + fir;
            Print();
            continue;
        }
        while (freq[fir]--)
            res[rlen++] = 'a' + fir;
        for (int i = sec + 1; i < Maxl; i++) if (freq[i] > 0) {
            res[rlen++] = 'a' + i;
            freq[i]--;
            break;
        }
        for (int i = sec; i < Maxl; i++)
            while (freq[i]--)
                res[rlen++] = 'a' + i;
        Print();
    }
    return 0;
}