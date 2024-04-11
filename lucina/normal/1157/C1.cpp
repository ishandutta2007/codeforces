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
        if(a[l]==a[r]){
            if(a[l]<=last){
                break;
            }
            pt1=l,pt2=r;
            while(a[pt1+1]==(a[pt2-1])&&pt1+1<pt2-1){
                pt1++;
                pt2--;
            }
            q=l;
            t=last;
            for(;q+1<=pt1;){
                if(a[q+1]>a[q])
                    q++;
            }
            g=r;
            for(;g-1>=pt2;){
                if(a[g-1]>a[g])
                    g--;
            }
            if(g==q+1){
                for(int j=l;j<=g;j++){
                    x.push_back('L');
                    numl++;
                }
                break;
            }
            if(a[q+1]>a[q]&&a[g-1]>a[g]&&a[q+1]<a[g-1]){
                for(int j=l;j<=q;j++){
                    x.push_back('L');
                    numl++;
                }
            l=1+numl;
            last=a[l-1];
            }
            else{
                for(int j=r;j>=g;j--){
                    x.push_back('R');
                    numr++;
                }
                r=n-numr;
                last=a[r+1];
            }
        }
        }
    printf("%d\n",x.size());
    for(char i:x){
        printf("%c",i);
    }



}