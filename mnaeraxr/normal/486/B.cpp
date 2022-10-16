#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define DB(x) cout << #x << " " << x << endl
#define MP make_pair
#define wait system("pause")

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MAXN = (int)1e5 + 10;

bool B[110][110];
bool A[110][110];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
//    memset(A, true, sizeof A);
    
    
    int r, c; cin >> r >> c;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            A[i][j] = true;
            
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            int v; cin >> v;
            B[i][j] = v;
            if (!B[i][j]){
               //DB(i); DB(j);
               for (int k = 0; k < r; ++k)
                   A[k][j] = false;
               for (int k = 0; k < c; ++k)
                   A[i][k] = false;
            }
        }
    }    
    /*
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    */
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            if (B[i][j]){
               bool valid = false;
               
               for (int k = 0; k < r && !valid; ++k){
                   if (A[k][j]) valid = true;
               }
               for (int k = 0; k < c && !valid; ++k){
                   if (A[i][k]) valid = true;
               }
               
               if (!valid){
                  cout << "NO" << endl;
                  //wait;
                  return 0;
               }
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cout << (A[i][j] ? 1 : 0) << " \n"[j == c - 1];
        }
    }  
    /*  
    cout << endl;
    wait;
    */
    return 0;
}