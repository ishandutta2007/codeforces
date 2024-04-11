#include <bits/stdc++.h>
using namespace std;

int A, B, C, D, E, F;

int main()
{
    cin >> A >> B >> C >> D >> E >> F;
    vector <int> arr = {A-D, B-E, C-F};
    int sum = 0;
    for (int t: arr){
        if (t > 0) sum += t/2*2;
        else sum += t+t;
    }
    puts(sum < 0 ? "No" : "Yes");
}