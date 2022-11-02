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

string S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> S;
    bool ans = 0;
    for (int i=0;i<sz(S);i++){
        for (int j=i;j<sz(S);j++){
            string s;
            for (int k=0;k<sz(S);k++){
                if (k < i || k > j) s.pb(S[k]);
            }
            if (s == "CODEFORCES") ans = 1;
        }
    }
    puts(ans ? "YES" : "NO");
}