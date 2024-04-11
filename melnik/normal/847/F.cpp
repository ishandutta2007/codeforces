#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

const int N = 1e5 + 10;

int c[N];
int n;
int last[N];
int g[N];

int get(int i){
    if(c[i]==0)return n + 1;
    int cnt=0;
    for(int j=1;j<=n;++j){
        if(j==i)continue;
        if(c[j]==0)continue;
        if(c[j]>c[i]||(c[j]==c[i]&&last[j]<last[i]))cnt++;
    }
    return cnt;
}

int main() {
//    ifstream cin( "input.txt" );
    int k, a,m;
    cin >> n >> k >> m >> a;
    for(int i = 1; i <= a; ++i) cin >> g[i];
    for(int i = 1; i <= n; ++i) {
        for(int j=1;j<=n;++j)c[j]=last[j]=0;
        for(int j=1;j<=a;++j)++c[g[j]], last[g[j]]=j;
        for(int j=a+1;j<=m;++j){
            int idx=-1;
            for(int p=1;p<=n;++p){
                if(p==i)continue;
                if(c[p]>c[i]||(c[p]==c[i]&&last[p]<last[i]))continue;
                if(idx==-1||c[p]>c[idx])idx=p;
            }
            if(idx!=-1)c[idx]++,last[idx]=j;
        }

        int cnt=get(i);
        if(cnt<k){
            cout<<1<<' ';
            continue;
        }

        for(int j=1;j<=n;++j)c[j]=last[j]=0;
        for(int j=1;j<=a;++j)++c[g[j]], last[g[j]]=j;

        for(int j=a+1;j<=m;++j)++c[i],last[i]=j;
        cnt=get(i);
        if(cnt<k){
            cout<<2<<' ';
        }else cout <<3<<' ';


    }
}