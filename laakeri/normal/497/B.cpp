#include <iostream>
#include <algorithm>

using namespace std;

int st1[100001];
int st2[100001];

int sum1(int a, int b){
    if (a==0) return st1[b];
    return st1[b]-st1[a-1];
}

int sum2(int a, int b){
    if (a==0) return st2[b];
    return st2[b]-st2[a-1];
}

int n;

int test(int t){
    int p1=0;
    int p2=0;
    int k=0;
    while (1){
        int mi=k;
        int ma=n-1;
        while (mi<=ma){
            int m=(mi+ma)/2;
            if (sum1(k, m)>=t||sum2(k, m)>=t){
                ma=m-1;
            }
            else{
                mi=m+1;
            }
        }
        if (mi>=n) return 0;
        if (sum1(k, mi)>=t){
            p1++;
            if (mi+1==n&&p1>p2) return p1;
        }
        else if (sum2(k, mi)>=t){
            p2++;
            if (mi+1==n&&p2>p1) return p2;
        }
        if (mi+1>=n) return 0;
        k=mi+1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        if (i){
            st1[i]+=st1[i-1];
            st2[i]+=st2[i-1];
        }
        if (a==1) st1[i]++;
        if (a==2) st2[i]++;
    }
    vector<pair<int, int> > v;
    for (int i=1;i<=n;i++){
        int a=test(i);
        if (a>0){
            v.push_back({a, i});
        }
    }
    cout<<v.size()<<endl;
    sort(v.begin(), v.end());
    for (auto vv:v){
        cout<<vv.first<<" "<<vv.second<<'\n';
    }
}