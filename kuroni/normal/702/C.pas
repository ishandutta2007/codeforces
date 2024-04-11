uses math;
var i, j, n, m: longint;
    r, tmp: int64;
    A,B: array[1..100000] of longint;
begin
  read(n,m);
  for i := 1 to n do read(A[i]);
  for j := 1 to m do read(B[j]);
  j := 1;
  for i := 1 to n do
  begin
    while ((B[j] <= A[i]) and (j < m)) do inc(j);
    if j = 1 then tmp := abs(A[i]-B[j]) else tmp := min(abs(A[i]-B[j]),abs(A[i]-B[j-1]));
    r := max(r,tmp);
  end;
  write(r);
end.