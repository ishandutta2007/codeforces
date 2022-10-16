#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;

void input(){
	scanf("%d", &N);
}

int main(){
	input();

    LL smallest = 1e18, biggest = -1;

    for(int B = 1; B*B <= N; B++){
        if(N % B != 0) continue;
        
        int Nb = N / B;

        for(int A = 1; A*A <= Nb; A++){
            if(Nb % A != 0) continue;

            int C = Nb / A;

            LL volume = ((LL)(A+1) * (B+2) * (C+2));
            smallest = min(smallest, volume);
            biggest  = max(biggest, volume);
        }

        for(int C = 1; C*C <= Nb; C++){
            if(Nb % C != 0) continue;

            int A = Nb / C;
            LL volume = ((LL)(A+1) * (B+2) * (C+2));
            smallest = min(smallest, volume);
            biggest  = max(biggest, volume);
        }
    }

    cout << smallest-N << " " << biggest-N << endl;
}