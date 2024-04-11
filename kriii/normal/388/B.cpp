#include <stdio.h>
#include <vector>
using namespace std;

int N,K,C; bool map[1010][1010];

void add(vector<int> a, vector<int> b)
{
    for (auto A:a) for (auto B:b){
        map[A][B] = map[B][A] = 1;
    }
}

int main()
{
    scanf ("%d",&K);

    int i,j;

    C = 2;
    vector<int> last,now;
    last.push_back(++C);
    last.push_back(++C);
    for (j=0;j<29;j++){
        now.push_back(++C);
        now.push_back(++C);
        add(last,now);
        last = now;
        now.clear();
    }
    now.push_back(2);
    add(last,now);

    for (i=30;i>=0;i--) if (K & (1 << i)){
        last.clear(); last.push_back(1);
        for (j=0;j<30-i;j++){
            now.clear(); now.push_back(++C);
            add(last,now);
            last = now;
        }
        now.clear();
        if (i == 0) now.push_back(2);
        else{
            now.push_back((30-i)*2+3);
            now.push_back((30-i)*2+4);
        }
        add(last,now);
    }

    printf ("%d\n",C);
    for (i=1;i<=C;i++,puts("")) for (j=1;j<=C;j++){
        putchar(map[i][j]?'Y':'N');
    }

    return 0;
}