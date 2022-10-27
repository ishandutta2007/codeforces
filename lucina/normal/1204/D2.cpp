#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
char s[maxn],res[maxn];
int n;
 
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
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