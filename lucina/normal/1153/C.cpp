#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
char s[maxn];
void badd(){
    printf(":(");
    exit(0);
}

int main(){
    scanf("%d%s",&n,s+1);
    if(n&1)
        badd();
        int l=0;
    for(int i=1;i<=n;i++)
    l+=(s[i]=='(');
    for(int i=1;i<=n;i++){
        if(s[i]=='?'){
            if(l<n/2)l++,s[i]='(';
            else s[i]=')';
        }
    }
    vector<char> a;
    for(int i=1;i<=n;i++){
        if(a.empty()){
            a.push_back(s[i]);
        }
        else{
            if(s[i]==')'&&a.back()=='(')
                a.pop_back();
            else
                a.push_back(s[i]);
        }
        if(a.empty()&&i!=n)badd();
    }
    if(!a.empty())badd();
        printf("%s",s+1);

}