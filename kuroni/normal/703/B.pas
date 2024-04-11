uses math;
var n, k, i, id1, id0: longint;
    sum, ans, p: int64;
    chk: boolean;
    A: array[0..100001] of longint;
begin
  id0 := -1; ans := 0; p := 0; sum := 0;
  read(n,k);
  for i := 1 to n do
  begin
    read(A[i]);
    inc(sum,A[i]);
  end;
  A[0] := A[n];
  A[n+1] := A[1];
  for i := 1 to n do inc(ans,A[i]*A[i+1]);
  for i := 1 to k do
  begin
    read(id1);
    if id1 = 1 then chk := true;
    inc(p,A[id1]);
    inc(ans,A[id1]*(sum-A[id1-1]-A[id1+1]-p));
    if id1 = id0 + 1 then inc(ans,A[id1]*A[id1-1]);
    if id1 = n then inc(ans,ord(chk)*A[n]*A[1]);
    id0 := id1;
  end;
  write(ans);
end.