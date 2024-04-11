#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define INF 1e9

const int MX=3e5;
int n=0, m, t=0;
string s;

int getTotLeft() {
    int tot=0;
    REP(i,0,m)
        if(s[i]!='?')
            tot += s[i]-'0';
    return tot;
}
int getTotRight() {
    int tot=0;
    REP(i,0,m)
        if(s[i+m]!='?')
            tot += s[i+m]-'0';
    return tot;
}
int getQLeft() {
    int tot=0;
    REP(i,0,m)
        if(s[i] == '?')
            tot++;
    return tot;
}
int getQRight() {
    int tot=0;
    REP(i,0,m)
        if(s[i+m] == '?')
            tot++;
    return tot;
}
bool pos() {
    int leftTot=getTotLeft(), rightTot=getTotRight();
    int L=getTotLeft()-getTotRight()+getQLeft()*9;
    int R=getTotLeft()-getTotRight()-getQRight()*9;
    return (L+R)/2 == 0;
}

int main() {
    cin>>n>>s; m=n/2;
    REP(i,0,n) t += s[i]=='?';
    if(pos()) cout<<"Bicarp"<<endl;
    else cout<<"Monocarp"<<endl;
}