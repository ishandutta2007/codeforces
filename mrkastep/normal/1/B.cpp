#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <string.h>

#define For(i,n) for(i=0;i<(n);i++)
#define pb push_back

bool letter(char c){
    if(c>='A'&&c<='Z') return true;
    return false;
}

std::string conv(int type,std::string s){
    if(type==0){
        std::string ans;
        int l=0,c=0,i=0,d=1;
        char ch[20];
        while(letter(s[i+1])) i++;
        while(i>=0){
            c+=d*(s[i]-'A'+1);
            d*=26;
            i--;
        }
        i=0;
        while(letter(s[i])){
            i++;
        }
        ans+='R';
        for(i=i;i<s.length();i++){
            ans+=s[i];
        }
        ans+='C';
        itoa(c,ch,10);
        ans+=ch;
        return ans;
    }
    else{
        std::string ans,col;
        int l=0,c=0,i,j,sz;
        char ch[20];
        for(i=1;!letter(s[i]);i++){
            l*=10;
            l+=(s[i]-'0');
        }
        i++;
        j=0;
        for(i=i;i<s.length();i++){
            ch[j]=s[i];
            j++;
        }
        ch[j]='\0';
        c=atoi(ch);
        c--;
        while(c>=0){
            col+=(char)(c%26+'A');
            c/=26;
            c--;
        }
        for(i=col.length()-1;i>=0;i--){
            ans+=col[i];
        }
        itoa(l,ch,10);
        ans+=ch;
        return ans;
    }
}



void solve(int n){
    int i,type,j;
    char c[20];
    std::string s;
    getchar();
    For(i,n){
        gets(c);
        s=c;
        if(!letter(s[0])){
            type=0;
        }
        else{
            j=1;
            while(letter(s[j])) j++;
            while(!letter(s[j])&&j<s.length()) j++;
            if(j==s.length()) type=0;
            else type=1;
        }
        printf("%s\n",conv(type,s).c_str());
    }

}

int main() {
#pragma comment(linker, "/STACK:67108864") 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}