#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,l,r,c1,c2;
char s[maxn];
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    //cout<<n<<'\n';
    for(int i=1;i<=n;i++){
        if(s[i]=='['){
            if(l==0)
                l=i;
        }
        else if(s[i]==']')
            r=i;
    }
    if(r<=l||l==0||r==0){
        printf("-1");
        return 0;
    }
  //  printf("%d %d\n",l,r);
    for(int i=l;i<=r;i++){
        if(s[i]==':'){
            c1=i;
            break;
        }
    }
    for(int i=r;i>=l;i--){
        if(s[i]==':'){
            c2=i;
            break;
        }
    }
    //printf("%d %d\n",c1,c2);
    if(c1==c2){
        printf("-1");
        return 0;
    }
    int sum=0;
    for(int i=c1;i<=c2;i++){
        if(s[i]=='|')
            sum++;
    }
    printf("%d\n",4+sum);

}