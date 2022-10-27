#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
char s[maxn];
vector<int> p;

int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='8'){
            p.push_back(i);
        }
    }
    int turn=(n-11)>>1;
    if(p.size()<=turn){
        printf("NO");
        return 0;
    }
    if(p[turn]-turn-1<=turn){
        printf("YES");
        return 0;
    }
    else{
        printf("NO");
        return 0;
    }
}
/*
Lucina
*/