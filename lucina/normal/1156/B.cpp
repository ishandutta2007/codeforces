#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int t,a[26],ct;
char s[105];

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        memset(a,0,sizeof(a));
        for(int i=0;s[i]!='\0';i++)
            a[s[i]-'a']++;
        ct=0;
        vector<int> b;
        for(int i=0;i<26;i++){
            ct+=(a[i]>0?1:0);
            if(a[i])
            b.push_back(i);
            }
        if(ct==2){
            if(b[0]+1==b[1]){
                printf("No answer\n");
            }
            else{
                printf("%s\n",s);
            }
            continue;
        }
        if(ct==3){
            if(b[1]==b[0]+1&&b[1]+1==b[2]){
                printf("No answer\n");
                continue;
            }
            if(b[0]+1<b[1]){
                for(int i=0;i<a[b[1]];i++)
                    printf("%c",b[1]+'a');
                for(int i=0;i<a[b[0]];i++)
                    printf("%c",b[0]+'a');
                for(int i=0;i<a[b[2]];i++)
                    printf("%c",b[2]+'a');
                printf("\n");continue;
            }
            if(b[1]+1<b[2]){
                for(int i=0;i<a[b[0]];i++)
                    printf("%c",b[0]+'a');
                for(int i=0;i<a[b[2]];i++)
                    printf("%c",b[2]+'a');
                for(int i=0;i<a[b[1]];i++)
                    printf("%c",b[1]+'a');
                printf("\n");continue;
            }
        }
        for(int j=0;j<b.size();j++){
            if(j&1){
                for(int i=0;i<a[b[j]];i++)
                    printf("%c",b[j]+'a');
            }
        }
        for(int j=0;j<b.size();j++){
            if(j%2==0){
                for(int i=0;i<a[b[j]];i++)
                    printf("%c",b[j]+'a');
            }
        }
        printf("\n");
    }
}