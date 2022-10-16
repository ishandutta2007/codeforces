#include<bits/stdc++.h>
#define ff(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAX=1e5+5,INF=1e9;



void init(void)
{
    int n,m;
    cin>>n>>m;
    int mx=min(m,n/2),res=0;
    ff(a,0,mx) res=max(res,a+min(n-2*a,(m-a)/2));
    cout<<res;
}

void process(void)
{

}

int main(void)
{
    init();
    process();
    return 0;
}