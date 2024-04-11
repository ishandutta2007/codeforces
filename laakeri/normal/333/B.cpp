#include <iostream>

using namespace std;

int nx[1001];
int ny[1001];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        nx[x]=1;
        ny[y]=1;
    }
    int cu=0;
    int c=0;
    if (n%2==1){
        c=n/2+1;
    }
    int v=0;
    for (int i=2;i<n;i++){
        if (nx[i]==0){
            if (i==c){
                if (cu==0){
                    v++;
                    cu=1;
                }
            }
            else v++;
        }
    }
    for (int i=2;i<n;i++){
        if (ny[i]==0){
            if (i==c){
                if (cu==0){
                    v++;
                    cu=1;
                }
            }
            else v++;
        }
    }
    cout<<v<<endl;
}