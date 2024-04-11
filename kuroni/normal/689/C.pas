uses math;
const bound = 4949100894494448;
var n, tmp: qword;
function FindNum(m: qword): qword;
var ans, tmp: qword;
    i: longint;
begin
  ans := 0;
  for i := 2 to trunc(power(m, 1/3)) do
  begin
    tmp := i;
    inc(ans,m div (tmp*tmp*tmp));
  end;
  exit(ans);
end;
function Reduce(m: qword): qword;
var tmp: qword;
begin
  tmp := m;
  repeat
    dec(tmp);
  until FindNum(tmp) < n;
  exit(tmp+1);
end;
function Search(n: qword): qword;
var l, r, mid, tmp: qword;
begin
  l := 2; r := bound;
  while l <= r do
  begin
    mid := (l + r) div 2;
    tmp := FindNum(mid);
    if tmp = n then exit(mid);
    if tmp < n then l := mid + 1 else r := mid - 1;
  end;
  exit(0);
end;
begin
  read(n);
  tmp := Search(n);
  if tmp = 0 then write('-1') else write(Reduce(tmp));
end.