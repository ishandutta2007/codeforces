#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
char s[maxn];
int pre[2][maxn],dp[2][maxn],n,pa[2][maxn];
char res[maxn];

int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    int zero=0;
    for(int i=1;i<=n;i++){
        pre[0][i]=pre[0][i-1]+(s[i]=='0');
        pre[1][i]=pre[1][i-1]+(s[i]=='1');
    }
    dp[s[1]-'0'][1]=1;
    for(int i=1;i<=n;i++){
        res[i]='0';
    }
    vector<int> st;
    for(int i=1;i<=n;i++){
        if(s[i]=='1'){
            st.push_back(i);
            res[i]='0';
            continue;
        }
        if(s[i]=='0'&&!st.empty()){
            res[st.back()]='1';
            st.pop_back();
        }
    }
    for(int i=1;i<=n;i++)
        printf("%c",res[i]);
}
/*
    Good Luck
        -Lucina
*/