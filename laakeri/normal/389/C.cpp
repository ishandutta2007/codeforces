#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> piles;
vector<int> boxes;

int main(){
    int n;
    cin>>n;
    int i;
    int a;
    for (i=0;i<n;i++){
        cin>>a;
        boxes.push_back(a);
    }
    sort(boxes.begin(),boxes.end());
    for (int b:boxes){
        int f=0;
        for (int i=0;i<piles.size();i++){
            if (piles[i]<=b){
                piles[i]++;
                f=1;
                break;
            }
        }
        if (!f){
            piles.push_back(1);
        }
    }
    cout <<piles.size()<<endl;
}