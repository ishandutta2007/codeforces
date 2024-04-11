#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <time.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long

int pos1=0,pos2=0;
vector<int> a1,a2;


int nxt(){
    if(pos1>=a1.size()) return a2[pos2];
    if(pos2>=a2.size()) return a1[pos1];
    return min(a1[pos1],a2[pos2]);
}



void solve(){
    int n,D=0,i,a,s1=0,s2=0,ans1,ans2;
    scanf("%d",&n);
    For(i,n){
        scanf("%d",&a);
        a1.pb(a);
        s1+=3;
    }
    scanf("%d",&n);
    For(i,n){
        scanf("%d",&a);
        a2.pb(a);
        s2+=3;
    }
    ans1=s1;
    ans2=s2;
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
    while(pos1<a1.size()||pos2<a2.size()){
        D=nxt();
        while(pos1<a1.size()&&a1[pos1]==D){
            pos1++;
            s1--;
        }
        while(pos2<a2.size()&&a2[pos2]==D){
            pos2++;
            s2--;
        }
        if(s1-s2>ans1-ans2){
            ans1=s1;
            ans2=s2;
        }
    }
    printf("%d:%d",ans1,ans2);

}

int main(){
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    
    solve();
    
    return 0;
}