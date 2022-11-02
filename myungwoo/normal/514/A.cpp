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

int main()
{
    ios_base::sync_with_stdio(false);
    lld X;
    cin >> X;
    lld ans = 0;
    vector <int> arr;
    for (;X;X/=10){
        arr.pb(min(X%10, 9-X%10));
    }
    reverse(all(arr));
    bool sw = 0;
    for (int d: arr){
        if (d) sw = 1;
        if (!sw) d = 9, sw = 1;
        ans = ans*10 + d;
    }
    cout << (ans ? ans : 9) << endl;
}