#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int ok[5010][5010];
map<char, char> rv;

void brute(int n){
    string s1,s2;
    cin>>s1>>s2;
    s1="Q"+s1;
    s2="Q"+s2;
    rv['N']='S';
    rv['S']='N';
    rv['E']='W';
    rv['W']='E';
    queue<pair<int, int> > bfs;
    bfs.push({1, 1});
    while (!bfs.empty()){
        auto x=bfs.front();
        bfs.pop();
        if (ok[x.F][x.S]) continue;
        ok[x.F][x.S]=1;
        //cout<<x.F<<" "<<x.S<<endl;
        for (auto t:rv){
            int p1=x.F;
            int p2=x.S;
            if (x.F<n&&s1[x.F]==t.F){
                p1=x.F+1;
            }
            if (x.S<n&&s2[x.S]==t.F){
                p2=x.S+1;
            }
            if (x.F>1&&s1[x.F-1]==t.S){
                p1=x.F-1;
            }
            if (x.S>1&&s2[x.S-1]==t.S){
                p2=x.S-1;
            }
            //cout<<"n "<<p1<<" "<<p2<<" "<<s1[x.F]<<endl;
            bfs.push({p1, p2});
        }
    }
    if (ok[n][n]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int dp[1010101];

int nn[1010101][2];
int ns[1010101][2];
int ne[1010101][2];
int nw[1010101][2];

void solve(int n, string s1, string s2){
    nn[n+1][0]=n+1;
    ns[n+1][0]=n+1;
    ne[n+1][0]=n+1;
    nw[n+1][0]=n+1;
    nn[n+1][1]=n+1;
    ns[n+1][1]=n+1;
    ne[n+1][1]=n+1;
    nw[n+1][1]=n+1;
    for (int i=n;i>=0;i--){
        nn[i][0]=nn[i+1][0];
        ns[i][0]=ns[i+1][0];
        ne[i][0]=ne[i+1][0];
        nw[i][0]=nw[i+1][0];
        nn[i][1]=nn[i+1][1];
        ns[i][1]=ns[i+1][1];
        ne[i][1]=ne[i+1][1];
        nw[i][1]=nw[i+1][1];
        if (s2[i]=='N') nn[i][0]=i;
        if (s2[i]=='S') ns[i][0]=i;
        if (s2[i]=='E') ne[i][0]=i;
        if (s2[i]=='W') nw[i][0]=i;
        if (s1[i]=='N') nn[i][1]=i;
        if (s1[i]=='S') ns[i][1]=i;
        if (s1[i]=='E') ne[i][1]=i;
        if (s1[i]=='W') nw[i][1]=i;
    }
    for (int i=0;i<=n+1;i++){
        dp[i]=0;
    }
    dp[1]=n+1;

    for (int i=1;i<=n+1;i++){
        int k=dp[i];
        int lm=n+1;
        //cout<<i<<" "<<k<<endl;
        if (i<=n){
            if (s1[i]=='N'){
                lm=min(lm, nn[k][0]);
            }
            if (s1[i]=='S'){
                lm=min(lm, ns[k][0]);
            }
            if (s1[i]=='E'){
                lm=min(lm, ne[k][0]);
            }
            if (s1[i]=='W'){
                lm=min(lm, nw[k][0]);
            }
        }
        if (i>1){
            if (s1[i-1]=='N'){
                lm=min(lm, ns[k][0]);
            }
            if (s1[i-1]=='S'){
                lm=min(lm, nn[k][0]);
            }
            if (s1[i-1]=='E'){
                lm=min(lm, nw[k][0]);
            }
            if (s1[i-1]=='W'){
                lm=min(lm, ne[k][0]);
            }
        }

        int lm2=n+1;
        if (k<=n){
            if (s2[k]=='N'){
                lm2=min(lm2, nn[i][1]);
            }
            if (s2[k]=='S'){
                lm2=min(lm2, ns[i][1]);
            }
            if (s2[k]=='E'){
                lm2=min(lm2, ne[i][1]);
            }
            if (s2[k]=='W'){
                lm2=min(lm2, nw[i][1]);
            }
        }
        if (k>1){
            if (s2[k-1]=='N'){
                lm2=min(lm2, ns[i][1]);
            }
            if (s2[k-1]=='S'){
                lm2=min(lm2, nn[i][1]);
            }
            if (s2[k-1]=='E'){
                lm2=min(lm2, nw[i][1]);
            }
            if (s2[k-1]=='W'){
                lm2=min(lm2, ne[i][1]);
            }
        }
        if (lm2>i){
            dp[lm2]=max(dp[lm2], k);
        }
        //cout<<i<<" "<<lm2<<" "<<k<<endl;
        k=max(k, lm);
        //cout<<i<<" "<<k<<endl;
        if (i==n+1){
            if (k==n+1){
                cout<<"YES"<<endl;
                exit(0);
            }
            return;
        }
        int nk=k;
        if (k<=n&&s2[k]==s1[i]){
            nk=k+1;
        }
        if (k>1){
            if (s2[k-1]=='E'&&s1[i]=='W') nk=k-1;
            if (s2[k-1]=='W'&&s1[i]=='E') nk=k-1;
            if (s2[k-1]=='S'&&s1[i]=='N') nk=k-1;
            if (s2[k-1]=='N'&&s1[i]=='S') nk=k-1;
        }
        dp[i+1]=max(dp[i+1], nk);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if (n<5000){
        brute(n);
        return 0;
    }
    n--;
    string s1,s2;
    cin>>s1>>s2;
    s1="Q"+s1;
    s2="Q"+s2;
    s1=s1+"Q";
    s2=s2+"Q";
    solve(n, s1, s2);
    solve(n, s2, s1);
    cout<<"NO"<<endl;
}