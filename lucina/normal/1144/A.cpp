#include<bits/stdc++.h>
using namespace std;
char s[105];
int n;

int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        vector<int> a;
        for(int i=0;s[i]!='\0';i++){
            a.push_back(s[i]-'a'+1);
        }
        sort(a.begin(),a.end());
        bool ch=true;
        for(int i=1;i<a.size();i++){
            if(a[i]-a[i-1]!=1)
            ch=false;
        }
        printf(ch?"YES\n":"NO\n");
    }


}