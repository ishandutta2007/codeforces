#include <iostream>
#include <vector>

using namespace std;

int LFT[200010];
int RHT[200010];
int CSUM[26][200010];

int main() {
  string A, B; cin >> A >> B;

  RHT[A.size()] = B.size();
  for(int i = A.size() - 1; i >= 0; i--) {
    RHT[i] = RHT[i + 1];
    if(RHT[i] && B[RHT[i] - 1] == A[i]) RHT[i]--;
  }
  LFT[0] = 0;
  for(int i = 0; i < A.size(); i++) {
    LFT[i + 1] = LFT[i];
    if(LFT[i + 1] < B.size() && B[LFT[i + 1]] == A[i]) LFT[i + 1]++;
  }

  for(int i = 0; i < B.size(); i++) {
    for(int j = 0; j < 26; j++) {
      CSUM[j][i + 1] = CSUM[j][i] + (B[i] == 'a' + j);
    }
  }

  for(int i = 0; i < A.size(); i++) {
    int a = max(RHT[i + 1] - 1, 0);
    int b = min(LFT[i] + 1, (int)B.size());
    if(a > b || CSUM[A[i] - 'a'][b] == CSUM[A[i] - 'a'][a]) {
/*
    bool ok = false;
    for(int j = max(b - 1, 0); j < min(a + 1, (int)B.size()); j++) {
      if(A[i] == B[j]) {
        ok = true;
      }
    }
    if(!ok) {
*/
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}