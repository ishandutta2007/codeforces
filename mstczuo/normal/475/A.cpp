# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

char A[][32] = {
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+" };
int main() {
    int n; cin >> n;
    for(int j = 1; j <= 21; j += 2)
        for(int i = 1; i <= 4; ++i) 
            if(n > 0 && A[i][j] == '#') A[i][j] = 'O', --n;
    for(int i = 0; i < 6; ++i)
        puts(A[i]);
    return 0;
}