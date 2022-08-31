#include <iostream>
#include <vector>
using namespace std;
    vector<int> k[100001];

int main() {
    int n;
    cin >> n;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        k[a].push_back(i);
    }int r = 0;
    for(int i = 1; i <= 100000; i++){
        if(k[i].size()>0){
            
            if(k[i].size() == 1){
                //cout << i << " 0\n";
                r++;
            } else {
                int p = k[i][1]-k[i][0];
                int yes = 0;
                for(int j = 0; j < k[i].size()-1; j++){
                    if(k[i][j+1] - k[i][j] != p){
                    
                        yes = 1;
                    }   }
                if(yes == 1) continue;
                //cout << i << " " << p << endl;
                r++;
            }
        }   
    }
    cout << r << endl;
    for(int i = 1; i <= 100000; i++){
        if(k[i].size()>0){
            if(k[i].size() == 1){
                cout << i << " 0\n";
            } else {
                int p = k[i][1]-k[i][0];
                int yes = 0;
                for(int j = 0; j < k[i].size()-1; j++){
                    if(k[i][j+1] - k[i][j] != p){

                        yes = 1;
                    }
                }
                if(yes == 1) continue;
                cout << i << " " << p << endl;
            }
        }   
    }
    return 0;
}