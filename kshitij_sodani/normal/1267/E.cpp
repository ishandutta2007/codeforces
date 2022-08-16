#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#define int long long
#define MOD 1000000007
#define mid(l, u) ((l+u)/2)
#define child(i) (i*2 + 1)
using namespace std;
int n, m;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return (a.first.first-a.first.second)>(b.first.first-b.first.second);
}
int solve(pair<pair<int, int>, int> arr[]){
    for(int i = 0;i<m;i++){
        //cout<<arr[i].first.first<<" "<<arr[i].first.second<<" "<<arr[i].second<<endl;
    }
    int sumours = arr[0].first.first;
    int sumtheirs = arr[0].first.second;
    int i = 0;
    while(sumours>=sumtheirs){
        i++;
        if(i>=m) break;
        sumours+=arr[i].first.first;
        sumtheirs+=arr[i].first.second;
    }
    //cout<<sumours<<" "<<sumtheirs<<endl;
    return (m-i);
}
void printans(pair<pair<int, int>, int> arr[]){
    int sumours = arr[0].first.first;
    int sumtheirs = arr[0].first.second;
    int i = 0;
    while(sumours>=sumtheirs){
        i++;
        if(i>=m) break;
        sumours+=arr[i].first.first;
        sumtheirs+=arr[i].first.second;
    }
    for(int j = i;j<m;j++){
        cout<<(arr[j].second+1)<<" ";
    }
    cout<<endl;
}
int32_t main(){
    cin>>n>>m;
    int vote[m][n];
    for(int i =0 ;i<m;i++){
        for(int j = 0;j<n;j++){
            cin>>vote[i][j];
        }
    }
    pair<pair<int, int>, int> arr[m];
    int minsize = 1e9;
    int minind = 0;
    for(int i = 0;i<(n-1);i++){
        //cout<<i<<endl;
        for(int j = 0;j<m;j++){
            arr[j].first.first = vote[j][i];
            arr[j].first.second = vote[j][n-1];
            arr[j].second = j;
        }
        sort(arr, arr+m, cmp);
        int temp = solve(arr);
        //cout<<temp<<endl;
        if(temp<minsize){
            minsize = temp;
            minind = i;
        }
    }
    cout<<minsize<<endl;
    for(int j = 0;j<m;j++){
        arr[j].first.first = vote[j][minind];
        arr[j].first.second = vote[j][n-1];
        arr[j].second = j;
    }
    //cout<<minind<<endl;
    sort(arr, arr+m, cmp);
    printans(arr);
}