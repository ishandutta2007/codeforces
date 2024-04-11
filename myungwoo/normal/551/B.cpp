#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

string A, B, C;
vector <int> cnt[3];

void count(const string &s, vector <int> &c)
{
    c.clear(); c.resize(26, 0);
    for (char ch: s) c[ch-'a']++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> A >> B >> C;
    count(A, cnt[0]); count(B, cnt[1]), count(C, cnt[2]);
    int ans = -1, p = 0, q = 0;
    for (int i=0;;i++){
        vector <int> tmp(26, 0);
        bool sw = 0;
        for (int j=0;j<26;j++){
            tmp[j] = cnt[0][j] - cnt[1][j]*i;
            if (tmp[j] < 0) sw = 1;
        }
        if (sw) break;
        int ot = 2e9;
        for (int j=0;j<26;j++) if (cnt[2][j]){
            ot = min(ot, tmp[j] / cnt[2][j]);
        }
        if (ans < i+ot)
            ans = i+ot, p = i, q = ot;
    }
    for (int i=p;i--;){
        for (int j=0;j<26;j++) cnt[0][j] -= cnt[1][j];
        cout << B;
    }
    for (int i=q;i--;){
        for (int j=0;j<26;j++) cnt[0][j] -= cnt[2][j];
        cout << C;
    }
    for (int i=0;i<26;i++) for (;cnt[0][i];cnt[0][i]--) cout << (char)(i+'a');
    cout << endl;
}