#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <time.h>
#include <queue>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long int


int main(){
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    while(read()) solve();
    char c1[111111];
    vector<int> r(111111,0);
    int i,no=0,nc=0,x=0,c,p,x1=0,x2=0;
    string s;
    gets(c1);
    s=c1;
    for(i=0;i<s.length();i++){
        if(s[i]=='(') no++;
        if(s[i]==')') nc++;
        if(s[i]=='#'){
            x++;
            p=i;
        }
        if(nc+x>no){
            printf("-1");
            return 0;
        }
    }
    c=no-nc;
    no=0;
    nc=0;
    int t=0;
    for(i=0;i<s.length();i++){
        if(s[i]=='#') t++;
        if(s[i]=='(') no++;
        if(s[i]==')') nc++;
        if(t==x){
            if(nc+c>no){
                printf("-1");
                return 0;
            }
        }
    }
    p++;
    while(p<s.length()){
        if(s[p]=='(') x1++;
        else x2++;
        p++;
    }
    if(x1>x2){
        printf("-1");
        return 0;
    }
    For(i,x-1){
        printf("1\n");
        c--;
    }
    printf("%d",c);



    return 0;
}