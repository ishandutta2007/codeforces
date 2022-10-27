#include<bits/stdc++.h>
using namespace std;
const int mm=1e5;
int n,f;
string ss;
char s[10];
double t,r;
long long a;
vector<pair<int,bool>> b;
long long ans;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf",&r);
        t=r*(double(1e5));
        a=(long long) t;
        bool l=(a%100000==0);
        b.push_back(make_pair(floor(r),l));
        ans+=(floor(r));
    }
    for(auto &i:b){
        if(ans==0)break;
        if(i.second)continue;
        if(ans<0){
            i.first++;
            ans++;
        }
        else if(ans>0){
            i.first--;
            ans--;
        }
        if(ans==0)break;
    }
    for(auto i:b)
        printf("%d\n",i.first);
}