#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
char s[maxn];
vector<char> g;

int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++){
        if(g.size()%2==0){
            g.push_back(s[i]);
        }
        else{
            if(s[i]!=g.back()){
                g.push_back(s[i]);
            }
        }
    }
    if(g.size()%2)g.pop_back();
    printf("%d\n",n-g.size());
    for(auto i:g)
        printf("%c",i);

}