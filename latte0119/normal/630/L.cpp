#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

signed main(){
    char s[10];cin>>s;
    int a=(s[0]-'0')*10000+(s[1]-'0')+(s[2]-'0')*1000+(s[3]-'0')*10+(s[4]-'0')*100;
    printf("%05lld\n",a*a%100000*a%100000*a%100000*a%100000);
    return 0;
}