#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct Node {
/*    int oneLeft, twoLeft;
    int oneRight, twoRight;
    int bestIncr, bestDecr;
    int size;
    bool is4Left, is4Right, inverted;*/

    int a4, a7, a47, a74;
    bool inverted;
};

Node join(const Node& left, const Node& right){
    Node result;

    assert(!left.inverted);
    assert(!right.inverted);
    result.inverted = false;

/*    result.is4Left  = left.is4Left;
    result.is4Right = right.is4Right;
    result.size     = left.size + right.size;
    result.inverted = false;

    // left side
    result.oneLeft = left.oneLeft;
    if(left.oneLeft == left.size && left.is4Right == right.is4Left)
        result.oneLeft = max(result.oneLeft, left.size + right.oneLeft);

    result.twoLeft = left.twoLeft;
//    fprintf(stderr, "Y %d\n", result.twoLeft);
    if(left.oneLeft == left.size){
        if(left.is4Right == right.is4Left)
            result.twoLeft = max(result.twoLeft, left.size + right.twoLeft);
        else
            result.twoLeft = max(result.twoLeft, left.size + right.oneLeft);
//        fprintf(stderr, "Y %d\n", result.twoLeft);
    }
    if(left.twoLeft == left.size && left.is4Right == right.is4Left)
        result.twoLeft = max(result.twoLeft, left.size + right.oneLeft);
//    fprintf(stderr, "Y %d\n", result.twoLeft);


    // right side
    result.oneRight = right.oneRight;
    if(right.oneRight == right.size && right.is4Left == left.is4Right)
        result.oneRight = max(result.oneRight, right.size + left.oneRight);

    result.twoRight = right.twoRight;
    if(right.oneRight == right.size){
        if(right.is4Left == left.is4Right)
            result.twoRight = max(result.twoRight, right.size + left.twoRight);
        else
            result.twoRight = max(result.twoRight, right.size + left.oneRight);
    }
    if(right.twoRight == right.size && left.is4Right == right.is4Left)
        result.twoRight = max(result.twoRight, right.size + left.oneRight);


    // best increases / decreases
    result.bestIncr = max(left.bestIncr, right.bestIncr);
    if(left.is4Right){
        if(right.is4Left)
            result.bestIncr = max(result.bestIncr, left.oneRight+right.twoLeft);
        else
            result.bestIncr = max(result.bestIncr, left.oneRight+right.oneLeft);
    } else if(!right.is4Left){
        result.bestIncr = max(result.bestIncr, left.twoRight+right.oneLeft);
    }


    result.bestDecr = max(left.bestDecr, right.bestDecr);
    if(!left.is4Right){
        if(!right.is4Left)
            result.bestDecr = max(result.bestDecr, left.oneRight+right.twoLeft);
        else
            result.bestDecr = max(result.bestDecr, left.oneRight+right.oneLeft);
    } else if(right.is4Left){
        result.bestDecr = max(result.bestDecr, left.twoRight+right.oneLeft);
    }
    
//    fprintf(stderr, ">>%d (%d,%d) (%d,%d)\n",
//            result.bestIncr, result.oneLeft, result.twoLeft,
//            result.oneRight, result.twoRight);*/
//
//
    result.a4 = left.a4 + right.a4;
    result.a7 = left.a7 + right.a7;
    result.a47 = max(left.a4 + right.a47, left.a47 + right.a7);
    result.a47 = max(result.a47, result.a4);
    result.a47 = max(result.a47, result.a7);
    result.a74 = max(left.a7 + right.a74, left.a74 + right.a4);
    result.a74 = max(result.a74, result.a4);
    result.a74 = max(result.a74, result.a7);

    return result;
}




Node invert_node(const Node& node){
    assert(node.inverted);

    Node result = node;
    swap(result.a4, result.a7);
    swap(result.a47, result.a74);
//    result.is4Left  = !result.is4Left;
//    result.is4Right = !result.is4Right;
//    swap(result.bestIncr, result.bestDecr);
    result.inverted   = false;

    return result;
}

Node make_node(char c){
    Node result;
    //result.size     = 1;
    result.inverted = false;
  
    result.a4 = (c=='4');
    result.a7 = (c=='7');
    result.a47 = result.a74 = 1;  
//    result.is4Left = result.is4Right = (c == '4');
//    result.bestIncr = result.bestDecr = 1;
//    result.oneLeft = result.twoLeft = result.oneRight = result.twoRight = 1;

    return result;
}


const int MaxSize = (1<<21);
const int MaxN = 1000005;
int Base;

Node tree[MaxSize];

void make_base(int N){
    Base = 1;
    while(Base < N) Base *= 2;
}

void propagate_tree(int N){
    int L = Base/2, R = (Base+N-1)/2;

    while(L){
        for(int i = L; i <= R; i++){
            tree[i] = join(tree[i*2], tree[i*2+1]);
        }
        L /= 2; R /= 2;
    }
}


void inv_node(int no, bool make_invert){
    if(make_invert)
        tree[no].inverted = !tree[no].inverted;

    if(tree[no].inverted){
        if(no < Base){
            tree[no*2].inverted = !tree[no*2].inverted;
            tree[no*2+1].inverted = !tree[no*2+1].inverted;
        }
        tree[no] = invert_node(tree[no]);
    }
}


void invert_rec(int L, int R, int node, int nodeL, int nodeR){
    inv_node(node, false); 

    if(nodeL > R || nodeR < L) return;
    if(nodeL >= L && nodeR <= R){
        inv_node(node, true);
        return;
    }

    int nodeMid = (nodeL + nodeR) / 2;
    invert_rec(L, R, node*2, nodeL, nodeMid);
    invert_rec(L, R, node*2+1, nodeMid+1, nodeR);

    tree[node] = join(tree[node*2], tree[node*2+1]);
}

void invert(int left, int right){
    invert_rec(left-1, right-1, 1, 0, Base-1);
}



int N, Q;
char data[MaxN];


void input(){
	scanf("%d%d", &N, &Q);
    scanf("%s", data);
}

int main(){
	input();
    make_base(N);

    for(int i = 0; i < N; i++){
        tree[Base+i] = make_node(data[i]);
    }
    for(int i = N; i < Base; i++){
        tree[Base+i].a4 = tree[Base+i].a7 = tree[Base+i].a47 = tree[Base+i].a74 = 0;
        //tree[Base+i].oneLeft = tree[Base+i].oneRight =
//            tree[Base+i].twoLeft = tree[Base+i].twoRight =
//            tree[Base+i].bestIncr = tree[Base+i].bestDecr = -2000;
    }

    propagate_tree(N);

    for(int query = 1; query <= Q; query++){
        char op[10];
        int L, R;
        scanf("%s", op);

        if(op[0] == 'c'){
            assert(!tree[1].inverted);
            printf("%d\n", tree[1].a47);
        } else {
            scanf("%d%d", &L, &R);
            invert(L, R);
        }
    }
}