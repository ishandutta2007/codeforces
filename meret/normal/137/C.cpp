#include <iostream> //scott ok so sort by a, then walk through and keep track of max value of b seen so far, all a are distinct so that helps
#include <algorithm> // meret fully agreed

using namespace std; //scott

typedef pair<int,int> PII;

int N; //scott

PII t[100005]; //meret

int main() { //scott wait do we have scanf
    cin >> N; // meret
    for (int i = 0; i < N; i++) //scott
        cin >> t[i].first >> t[i].second; // meret
    
    sort (t, t + N); //scott
    int mx = -1; // meret
    int ans = 0; //scott increase this by 1 each time t[i].second < mx
    for (int i = 0; i < N; ++i) {
        if (t[i].second < mx) ans++; //scott
        else mx = t[i].second;
    }//scott
    cout << ans << endl; // meret
}//scott GG