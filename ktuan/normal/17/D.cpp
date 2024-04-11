#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

char buf[3000030];
char *sa,*sb,*sc;
int c, z;
long long ac,res;
int bd2, bd4,bd8;

int main() {
    gets(buf);
    sa=strtok(buf," ");
    sb=strtok(NULL," ");
    sc=strtok(NULL," ");
    c=0;
    for(int i=0;sc[i]!=0;++i)c=c*10+sc[i]-'0';
    // a mod c
    ac=0;
    for(int i=0;sa[i]!=0;++i)
    {
        ac=ac*10+sa[i]-'0';
        ac %= c;    
    }
    z=ac;
    res=(z+c-1)%c;
    int bd=z;
    int nb=strlen(sb);
    {
        int i=nb-1;
        while(sb[i]=='0')sb[i]='9',--i;
        sb[i]--;
    }
    Ford(i,nb-1,0){
        int dig=sb[i]-'0';
        int t=bd,r=1;
        Rep(j,4){
            if((dig&(1<<j))!=0){
                //cout<<t<<endl;
                r=(long long)r*t%c;
            }
            t=(long long)t*t%c;
        }   
        res=res*r%c;
        bd2=(long long)bd*bd%c;
        bd4=(long long)bd2*bd2%c;
        bd8=(long long)bd4*bd4%c;
        bd=(long long)bd2*bd8%c;
        //cout<<dig<<" "<<r<<endl;
    }
    if(res==0)cout<<c<<endl;
    else cout<<res<<endl;
    return 0;   
}