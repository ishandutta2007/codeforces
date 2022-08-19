#include<bits/stdc++.h>
using namespace std;
long long ar[500005];
long long big[500005];
int n;
vector<long long> mg(vector<long long> a, vector<long long> b){
    int p1 = 0;
    int p2 = 0;
    vector<long long> ret;
    ret.push_back(0LL);
    while(p1+1<a.size() || p2+1<b.size()){
        bool add1 = false;
        if(p1+1==a.size()){
            //add2
        }
        else if(p2+1==b.size()){
            //add1
            add1 = true;
        }
        else{
            if(a[p1+1]-a[p1]>=b[p2+1]-b[p2]){
                add1 = true;
            }
        }
        if(add1){
            p1++;
        }
        else{
            p2++;
        }
        ret.push_back(a[p1]+b[p2]);
    }
    return ret;
}
vector<long long> comb(vector<long long> a, vector<long long> b){
    if(a.size()>b.size()){
        swap(a,b);
    }
    vector<long long> ret;
    for(int i = 0; i<a.size(); i++){
        ret.push_back(max(a[i],b[i]));
    }
    for(int i = a.size(); i<b.size(); i++){
        ret.push_back(b[i]);
    }
    return ret;
}
vector<vector<long long> > go(int l, int r){
    if(l==r){
        vector<long long> ret1;
        vector<vector<long long> > ret;
        ret1.push_back(0LL);
        ret1.push_back(ar[l]);
        ret.push_back(ret1);
        ret1.resize(1);
        for(int i = 0; i<3; i++){
            ret.push_back(ret1);
        }
        return ret;
    }
    int mid = (l+r)/2;
    vector<vector<long long> > a = go(l,mid);
    vector<vector<long long> > b = go(mid+1,r);
    vector<vector<long long> > ret;
    //0
    ret.push_back(comb(mg(a[1],b[0]),mg(a[0],b[2])));
    //1 01
    ret.push_back(comb(mg(a[1],b[1]),mg(a[0],b[3])));
    //2 10
    ret.push_back(comb(mg(a[3],b[0]),mg(a[2],b[2])));
    //3 11
    ret.push_back(comb(mg(a[3],b[1]),mg(a[2],b[3])));
    
    return ret;
    // if(!cl){
    //     l++;
    // }
    // if(!cr){
    //     r--;
    // }
    // vector<long long> ret;
    // ret.push_back(0);
    // if(l>r){
    //     return ret;
    // }
    // if(l==r){
    //     ret.push_back(ar[l]);
    //     return ret;
    // }
    // int mid = (l+r)/2;
    // //use mid
    // ret.push_back(ar[mid]);
    
    // ret = mg(mg(ret,go(true,false,l,mid-1)),go(false,true,mid+1,r));
    // //don't use mid
    // ret = comb(ret,mg(go(true,true,l,mid-1),go(true,true,mid+1,r)));
    // return ret;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k >> n;
    for (int i = 0; i < n; i++){
		cin >> big[i];
	}
	sort(big, big + n);
	n--;
 
    for(int i = 0; i<n; i++){
        ar[i] = big[i] - big[i + 1];
    }
    vector<vector<long long> > ans = go(0,n-1);
    cout << -ans[0][k] << endl;
    return 0;
}