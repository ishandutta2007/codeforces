#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long> array(0);
    for (int i = 0; i < n; ++i){
        long el;
        cin >> el;
        array.push_back(el);
    }
    sort(array.begin(), array.end());
    int number = 1;
    for (int i = 0; i < n; ++i){
        if (array[i] < number){
            continue;
        }
        ++number;
    }
    cout << number << endl;
}