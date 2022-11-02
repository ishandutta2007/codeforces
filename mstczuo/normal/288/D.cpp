# include <iostream>
# include <cstdio>
# include <vector>
using namespace std;
const int N=100000;
vector<int> g[N];
long long ans;
int s[N],n;

long long f(long long x){
    return x*(x-1)>>1;
} 

void solve(int x,int fa){
    long long A=0, B=0; s[x]=1;
    for(int i=0;i<g[x].size();i++)
        if(g[x][i]!=fa)solve(g[x][i],x);
    for(int i=0;i<g[x].size();i++)
        if(g[x][i]!=fa)s[x]+=s[g[x][i]];
    A=(long long)(n-s[x])*s[x];
    for(int i=0;i<g[x].size();i++)
        if(g[x][i]!=fa) B+=f(s[g[x][i]]);
    B = f(s[x])-B;
    //cout <<x<<' '<<A<<' '<<B<<endl; 
    ans -= A*B + f(B);
}

void getInt(int &res){
    char c;
    while(!isdigit(c=getchar()));
    res = c - '0';
    while( isdigit(c=getchar()))
        res = res * 10 + c - '0';
}

int main()
{
    //freopen("input.txt","r",stdin); 
    getInt(n); ans = f(f(n));
    for(int i=1;i<n;i++){
        int x, y;
        getInt(x); getInt(y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    solve(1,0);
    cout << (ans<<1) << endl;
    //while(1);
    return 0;
}