class solver1676H:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))
        self.inversions = 0

    def merge_sort(self, l, r):
        if l == r:
            return

        av = (l+r)//2

        self.merge_sort(l, av)
        self.merge_sort(av+1, r)

        fnl = []

        pointer_l = l
        pointer_r = av+1

        while pointer_l <= av and pointer_r <= r:
            if self.inp[pointer_l] < self.inp[pointer_r]:
                fnl.append(self.inp[pointer_l])
                self.inversions += pointer_r-(av+1)
                pointer_l += 1
            else:
                fnl.append(self.inp[pointer_r])
                pointer_r += 1

        while pointer_l <= av:
            fnl.append(self.inp[pointer_l])
            self.inversions += pointer_r - (av + 1)
            pointer_l += 1

        while pointer_r <= r:
            fnl.append(self.inp[pointer_r])
            pointer_r += 1

        for i in range(0, len(fnl)):
            self.inp[l+i] = fnl[i]

    def solve(self):

        self.merge_sort(0, self.n - 1)

        return self.inversions


t = int(input())

while t:
    t -= 1

    cur = solver1676H()

    print(cur.solve())