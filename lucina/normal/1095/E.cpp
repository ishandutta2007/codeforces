#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,b[maxn][2],x1,y1;
char s[maxn],x,y;
stack<pair<char,int>> a;

int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;s[i]!='\0';i++){
        b[i][0]=b[i-1][0],b[i][1]=b[i-1][1];
        if(s[i]=='(')
            b[i][0]++;
        else
            b[i][1]++;
        if(a.empty()){
            a.push({s[i],i});
        }
        else{
            if(a.top().first=='('&&s[i]==')'){
                a.pop();
            }
            else{
                a.push({s[i],i});
            }
        }
    }
    if(a.size()!=2){
        printf("0");
        return 0;
    }
    x=a.top().first;
    x1=a.top().second;
    a.pop();
    y=a.top().first;
    y1=a.top().second;
    if(x!=y){
        printf("0");
        return 0;
    }
    printf("%d\n",x=='('?b[n][0]-b[x1][0]+1:b[y1][1]);

}