#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],pt1,pt2,q,t,g,numl,numr;
char s[maxn];
vector<char> x;


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int l=1,r=n,last=0;
    for(int i=1;i<=n;i++){
        l=1+numl;r=n-numr;
    if(l==r){
            if(a[l]>last){
                x.push_back('L');
                numl++;
            }
            break;
        }
        if(a[l]<a[r]&&a[l]>last){
            x.push_back('L');
            numl++;
            last=a[l];
            continue;
        }
        if(a[l]>a[r]&&a[r]>last){
            last=a[r];
            x.push_back('R');
            numr++;
            continue;
        }
        if(a[l]<=last&&a[r]>last){
            last=a[r];
            x.push_back('R');
            numr++;
            continue;
        }
        if(a[r]<=last&&a[l]>last){
            last=a[l];
            x.push_back('L');
            numl++;
            continue;
        }
        if(a[l]<=last&&a[r]<=last){
            break;
        }
        if(a[l]==a[r]){

         q=l;g=r;
           while(a[q+1]>a[q]&&q+1<=r){
            q++;
           }
           while(a[g-1]>a[g]&&g-1>=l){
           g--;
           }
         //  cout<<l<<" "<<r<<" "<<q<<" "<<g<<endl;
           if(q-l>r-g){
                for(int j=0;j<=q-l;j++)
                    x.push_back('L');
           }
           else{
            for(int j=0;j<=r-g;j++)
                x.push_back('R');

        }
        break;
        }
        }
    printf("%d\n",x.size());
    for(char i:x){
        printf("%c",i);
    }
    }