#include <iostream>
#include <vector>
#include <algorithm>
#define F first
#define S second

typedef long long ll;

using namespace std;

int div1[4002];
int div2[4002];

int main(){
    int x,k;
    cin>>x>>k;
    div2[x]=1;
    for (int i=0;i<k;i++){
        int a,b,c;
        cin>>a;
        if (a==1){
            cin>>b>>c;
            div1[c]=1;
            div2[b]=1;
        }
        else{
            cin>>b;
            div2[b]=1;
        }
    }
    int ma=0;
    int mi=0;
    int j=0;
    int ja=0;
    for (int i=1;i<=x;i++){
        if (!div1[i]&&!div2[i]){
            ma++;
            if (j==0){
                ja=i;
            }
            j++;
        }
        else{
            if (j>0){
                mi+=(j/2);
                if (j%2>0){
                    mi++;
                }
            }
            j=0;
        }
    }
    cout <<mi<<" "<<ma<<endl;
}