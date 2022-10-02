#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
#define x first
#define y second

int main() {
    int N, M; cin >> N >> M;
    vector<vector<char>> Ans(N, vector<char>(M, '.'));
    int Plows = 0;
    

    if (N > 2 && M > 2) {
        vector<vector<pii>> E{
            {}, 
            {{0,0}, {0,1}, {0,2}, {1,1}, {2,1}},
            {{0,1}, {1,1}, {2,0}, {2,1}, {2,2}},
            {{0,0}, {1,0}, {1,1}, {1,2}, {2,0}},
            {{0,2}, {1,0}, {1,1}, {1,2}, {2,2}}
        };
        vector<int> Mask;
        for (int e = 0; e < E.size(); ++e) {
            int mask = 0;
            for (pii f: E[e]) mask |= 1<<(2*M+2-M*f.x-f.y);
            Mask.push_back(mask);
        }

        int st = 1<<(2*M+2);
        vector<vector<int>> A((N-2)*(M-1)+1, vector<int>(st, 0));
        for (int i = 0; i < N-2; ++i) {
            for (int j = 0; j < st; ++j) {
                int z = A[i*(M-1)][j]>>24<<24;
                A[i*(M-1)+1][j>>2] = max(A[i*(M-1)+1][j>>2], z|j); 
            }

            for (int k = 1; k < M-1; ++k) {
                for (int j = 0; j < st; ++j) {
                    for (int e = 0; e < E.size(); ++e) {
                        if ((j&Mask[e])==0) {
                            int z = i*(M-1)+k, y = (j|Mask[e])>>1;
                            A[z+1][y] = max(A[z+1][y], (((A[z][j]>>24) + (e!=0))<<24) | (j|(e<<20)));
                        }
                    }
                }
            }
        }

        auto cur = *max_element(A[(N-2)*(M-1)].begin(),A[(N-2)*(M-1)].end());
        Plows = cur>>24;
        char l = 'A';
        for (int i = (N-2)*(M-1)-1; i >= 0; --i) {
            int r = 2+i/(M-1), c = i%(M-1)+1;
            int t = cur>>20&15;
            if (t != 0) {
                for (pii e: E[t]) Ans[r-e.x][c-e.y] = l; 
                l++;
            }
            cur = A[i][cur&((1<<20)-1)];
        }
        
    }

    cout << Plows << endl;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cout << Ans[r][c];
        }
        cout << '\n';
    }
}