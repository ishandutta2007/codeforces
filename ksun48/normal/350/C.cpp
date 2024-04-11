#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int,pair<int,int> > k[n];
    for(int i = 0; i < n; i++){
        cin >> k[i].second.first >> k[i].second.second;
        k[i].first = abs(k[i].second.first)+abs(k[i].second.second);
    }
    sort(k, k+n);
    int j = 0;
    j += 2*n;
    for(int i = 0; i < n; i++){
        if(k[i].second.first != 0){
            j+= 2;
        }
        if(k[i].second.second != 0){
            j+=2;
        }
    }
    cout << j << endl;
    for(int i = 0; i < n; i++){
        if(k[i].second.first > 0){
            cout << "1 " << k[i].second.first << " R" << endl;
        } else if(k[i].second.first < 0){
            cout << "1 " << -k[i].second.first <<" L" <<  endl;
        }
        if(k[i].second.second > 0){
            cout << "1 " <<  k[i].second.second << " U" <<endl;
        } else if(k[i].second.second < 0){
            cout << "1 " << -k[i].second.second << " D" << endl;
        }
        cout << 2 << endl;
        if(k[i].second.first > 0){
            cout << "1 " << k[i].second.first << " L" << endl;
        } else if(k[i].second.first < 0){
            cout << "1 " << -k[i].second.first << " R" << endl;
        }
        if(k[i].second.second > 0){
            cout << "1 " << k[i].second.second << " D" << endl;
        } else if(k[i].second.second < 0){
            cout << "1 " << -k[i].second.second << " U" << endl;
        }
        cout << 3 << endl;
    }
    return 0;
}