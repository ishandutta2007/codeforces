uses math;
type point = record
  x, y: longint;
end;
var A: array[0..10001] of point;
    w, v, u, n, y: int64;
    i: longint;
    t, tmp: real;

function Hit:boolean;
var before, after: boolean;
    i: longint;
begin
  before := false;
  after := false;
  for i := 1 to n do
  begin
    if A[i].x-(A[i].y/u)*v > 0 then before := true;
    if A[i].x-(A[i].y/u)*v < 0 then after := true;
    if (before and after) then exit(true);
  end;
  exit(false);
end;

procedure QuickSort(L, H: int64);
var i, j: int64;
    tmp, lel: point;
begin
  i := L;
  j := H;
  lel := a[random(H-L+1)+L];
  repeat
    while A[i].y < lel.y do inc(i);
    while A[j].y > lel.y do dec(j);
    if i <= j then
    begin
      tmp := a[i];
      a[i] := a[j];
      a[j] := tmp;
      inc(i);
      dec(j);
    end;
  until i>j;
  if L<j then QuickSort(L,j);
  if i<H then QuickSort(i,H);
end;
begin
  readln(n,w,v,u);
  A[n+1].x := 0;
  A[n+1].y := w;
  for i := 1 to n do read(A[i].x,A[i].y);
  QuickSort(1,n);
  y := 0;
  if Hit then for i := 1 to n+1 do
  begin
    tmp := A[i].x - v*t;
    t := t+max(tmp/v,(A[i].y-y)/u);
    y := A[i].y;
  end else t := w/u;
  write(t);
end.