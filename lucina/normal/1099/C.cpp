#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int k,f[maxn];
vector <int> pos1;
vector <int> pos2;
char s[maxn];
int main(){
    bool ch=false;
    scanf("%s",s);
    cin>>k;
    int n=0,a=0,b=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]!='?'&&s[i]!='*'){
            n++;
            continue;
        }
        else{
            if(s[i]=='?'){
                a++;
                pos1.push_back(i);
            }
            else if(s[i]=='*'){
                b++;
                pos2.push_back(i);
            }
        }
    }
    if(b>0&&n-a-b>k){
        cout<<"Impossible";
        return 0;
    }
    if(b>0&&n-a-b<=k){
        for(int i=0;i<pos1.size();i++){
            f[pos1[i]]=1e9;
            f[pos1[i]-1]=1e9;
        }
        f[pos2[0]-1]=1;
        f[pos2[0]]=1e9;
        for(int i=1;i<pos2.size();i++){
            f[pos2[i]]=1e9;
            f[pos2[i]-1]=1e9;
        }
        for(int i=0;s[i]!='\0';i++){
            if(f[i]==0){
                printf("%c",s[i]);
            }
            else if(i==pos2[0]-1){
                for(int j=0;j<k-n+a+b;j++){
                    printf("%c",s[i]);
                }
            }
        }
        return 0;
    }
    else{
        if(n<k||n-a>k){
            cout<<"Impossible";
            return 0;
        }
        int dif=n-k;
        for(int i=0;i<dif;i++){
            f[pos1[i]-1]=1e9;
            f[pos1[i]]=1e9;
        }
        for(int i=0;s[i]!='\0';i++){
            if(f[i]==0){
                if(s[i]!='?'&&s[i]!='*')
                    printf("%c",s[i]);
            }
        }
    }


}