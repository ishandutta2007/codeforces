class solver_1681D:

    def __init__(self):
        self.n,self.x=list(map(int,input().split(' ')));

    def solve(self):

        queue=[[self.x,0]];

        pointer=0;

        seen={};

        while pointer<len(queue):
            x=queue[pointer][0];
            d=queue[pointer][1];

            pointer=pointer+1;

            if x in seen:
                continue;

            seen[x]=d;

            if x >= (10**(self.n-1)):
                return d;

            mult=[0 for _ in range(0,10)];

            mem_x=x;

            while mem_x:
                mult[mem_x%10]=1;
                mem_x=mem_x//10;

            for i in range(2,10):
                if mult[i]!=0:
                    queue.append([x*i,d+1]);

        return -1;

cur=solver_1681D();

print(cur.solve());