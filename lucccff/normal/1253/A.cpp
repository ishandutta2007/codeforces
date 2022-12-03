#include <iostream>
using namespace std;

/*void kmp_pre(int x[],int m,int next[]){
    int i,j;
    j=next[0]=1;
    i=0;
    while(i<m){
        while(1!=j && x[i]!=x[j])j=next[j];
        next[++i]=++j;
    }
}
void preKMP(int x[],int m,int kmpNext[]){
    int i,j;
    j=kmpNext[0]=1;
    i=0;
    while(i<m){
        while(1!=j && x[i]!=x[j])j=kmpNext[j];
        if(x[++i]==x[++j])kmpNext[i]=kmpNext[j];
        else kmpNext[i]=j;
    }
}

int next[100010];
int KMP_Count(int x[],int m,int y[],int n){//x y 
    int i,j;
    int ans=0;
    //preKMP(x,m,next);
    kmp_pre(x,m,next);
    i=j=0;
    while(i<n){
        while(1!=j && y[i]!=x[j])j=next[j];
        i++;j++;
        if(j>=m){
            ans++;
            j=next[j];
        }
    }
    return ans;
}*/

int main(){
    int i,j,k,l,m,n,t;
    int a[100010],b[100010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) cin>>a[j];
        for(j=0;j<n;j++) cin>>b[j];
        /*int f=0;
        k=0;
        for(j=0;j<n;j++) {
            if (b[j]>a[j]) {
                if (f==0) {
                    f=1;
                    k=b[j]-a[j];
                    break;
                }
            }
            if (b[j]<a[j]) {
                f=-1;
                break;
            }
        }
        if (f==1) {
            while(j<n&&b[j]!=a[j]) {
                if (k!=b[j]-a[j]) break;
                j++;
            }
            if (b[j]>a[j]&&b[j]-a[j]!=k) {
                cout<<"NO\n";
                continue;
            }
            for(;j<n;j++) {
                if (b[j]!=a[j]) break;
            }
            if (j!=n) {
                cout<<"NO\n";
                continue;
            }
            else {
                cout<<"YES\n";
            }
        }
        else if (f==-1) {
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
        }*/
        for(j=0;j<n;j++) {
            if (b[j]!=a[j]) {
                break;
            }
        }
        if (j==n) {
            cout<<"YES\n";
        }
        else if (b[j]>a[j]) {
            k=b[j]-a[j];
            while(j<n&&k==b[j]-a[j]) {
                j++;
            }
            while(j<n&&b[j]==a[j]) {
                j++;
            }
            if (j==n) {
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}