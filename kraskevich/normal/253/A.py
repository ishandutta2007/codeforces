inputFile = open('input.txt', 'r')
outputFile = open('output.txt', 'w')
n, m = map(int, inputFile.readline().split())
if n >= m:
    outputFile.write("BG" * m + "B" * (n - m))
else:
    outputFile.write("GB" * n + "G" * (m - n))