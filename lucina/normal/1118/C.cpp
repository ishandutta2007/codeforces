#include<bits/stdc++.h>
using namespace std;
int n,u,v,ct,x,m[25][25];
vector<pair<int,int>> a;
vector<int> b;
int main(){
    scanf("%d",&n);
    for(int i=n*n;i>=1;i--){
        scanf("%d",&u);
        b.push_back(u);
    }
    //cout<<"BUG";
    sort(b.begin(),b.end());
    for(int i=0;i<n*n;i++){
        x=b[i],ct=0;
        while(b[i]==x&&i<n*n){
            i++;
            ct++;
        }
        i--;
        a.push_back({ct,x});
    }
  /*  for(int i=0;i<a.size();i++){
        printf("%d %d\n",a[i].first,a[i].second);
    }*/
  /*  sort(a.begin(),a.end());
    reverse(a.begin(),a.end());*/

    ct=0;
    for(int i=1;i<=n/2;i++){
        for(int j=1;j<=n/2;j++){
            for(int k=0;k<a.size();k++){
                if(a[k].first>=4){
                    x=a[k].second;
                    m[i][j]=x;
                    m[n-i+1][j]=x;
                    m[n-i+1][n-j+1]=x;
                    m[i][n-j+1]=x;
                    a[k].first-=4;
                    break;
                }
            }
        }
    }
    if(n%2){
        for(int i=1;i<=n/2;i++){
            for(int j=0;j<a.size();j++){
                if(a[j].first>=2){
                    m[i][n/2+1]=a[j].second;
                    m[n-i+1][n/2+1]=a[j].second;
                    a[j].first-=2;
                    break;
                }
            }
        }
         for(int i=1;i<=n/2;i++){
            for(int j=0;j<a.size();j++){
                if(a[j].first>=2){
                    m[n/2+1][i]=a[j].second;
                    m[n/2+1][n-i+1]=a[j].second;
                    a[j].first-=2;
                    break;
                }
        }
    }
    for(int i=0;i<a.size();i++){
        if(a[i].first>0){
            m[n/2+1][n/2+1]=a[i].second;
            a[i].first--;
            break;
        }
    }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(m[i][j]==0){
            printf("NO");
            return 0;
            }
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}