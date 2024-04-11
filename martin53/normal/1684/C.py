import sys
def get_ints(): return list(map(int, sys.stdin.readline().strip().split()))

class solver_1684C:

    def __init__(self):
        self.n,self.m=list(map(int,input().split(' ')));

        self.inp=[];

        for i in range(self.n):
            self.inp.append(get_ints());

    def solve(self):

        #print(self.n,self.m,self.inp);

        l=0;
        r=0;

        for i in range(self.n):

            sorted=self.inp[i].copy();

            sorted.sort();

            wrong_ids=[];

            for j in range(self.m):
                if self.inp[i][j]!=sorted[j]:
                    wrong_ids.append(j);

            #print("i=",i,"wrong_ids=",wrong_ids);

            if len(wrong_ids)>=3:
                print("-1");
                return;

            if len(wrong_ids)==2:
                 l=wrong_ids[0]
                 r=wrong_ids[1];

                 break;

        for i in range(self.n):
            temp=self.inp[i][l];
            self.inp[i][l]=self.inp[i][r];
            self.inp[i][r]=temp;

        for i in range(self.n):
            for j in range(1,self.m):
                if self.inp[i][j]<self.inp[i][j-1]:
                    print("-1");
                    return;

        print(l+1,r+1);

t=int(input());

while t:
    t=t-1;

    cur=solver_1684C();

    cur.solve();