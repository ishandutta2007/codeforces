#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n, m;
    cin >> n >> m;
    //vector<int> bad = {2,3,3,2,2,2,1,2,2,1,1,3,3,1};
    if(n == 1 && m == 1){
        cout << "YES" << endl;
        cout << "1" << endl;
        return 0;
    }
    if(n == 3 && m == 3){
        cout << "YES" << endl;
        cout << "3 9 5" << endl;
        cout << "8 1 7" << endl;
        cout << "4 6 2" << endl;
        return 0;
    }
    if(n <= 3 && m <= 3){
        cout << "NO" << endl;
        return 0;
    }
    if(n == 4){
        cout << "YES" << endl;
        int a[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = i*m+j + 1;
            }
        }
        for(int j = 0; j < m; j++){
            swap(a[1][j], a[2][j]);
            swap(a[0][j], a[2][j]);
            swap(a[1][j], a[3][j]);
            if(j % 2){
                swap(a[0][j], a[3][j]);
                swap(a[1][j], a[2][j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }
    if(m == 4){
        cout << "YES" << endl;
        int a[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = i*m+j + 1;
            }
        }
        for(int i = 0; i < n; i++){
            swap(a[i][1], a[i][2]);
            swap(a[i][0], a[i][2]);
            swap(a[i][1], a[i][3]);
            if(i % 2){
                swap(a[i][0], a[i][3]);
                swap(a[i][1], a[i][2]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }
    if(n >= 5){
        cout << "YES" << endl;
        int a[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = i*m+j + 1;
            }
        }
        vector<int> d[m];
        for(int j = 0; j < m; j++){
            for(int i = j%2; i < n; i += 2){
                d[j].push_back(a[i][j]);
            }
            for(int i = 1-j%2; i < n; i += 2){
                d[j].push_back(a[i][j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << d[j][i] << " ";
            }
            cout << endl;
        }
        return 0;
    }
    if(m >= 5){
        cout << "YES" << endl;
        int a[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = i*m+j + 1;
            }
        }
        vector<int> d[n];
        for(int i = 0; i < n; i++){
            for(int j = i%2; j < m; j += 2){
                d[i].push_back(a[i][j]);
            }
            for(int j = 1-i%2; j < m; j += 2){
                d[i].push_back(a[i][j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }    
    /*if(n >= 4 && m >= 4){
        cout << "YES" << endl;
        int a[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = i*m+j + 1;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i % 2; j + 2 < m; j += 2){
                swap(a[i][j], a[i][j+2]);
            }
        }
        for(int j = 0; j < m; j++){
            for(int i = j % 2; i + 2 < m; i += 2){
                swap(a[i][j], a[i+2][j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }*/

}