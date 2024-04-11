{$APPTYPE CONSOLE}
uses SysUtils, Math;

var
  d, f : array[1..2000] of integer;
  n, i : integer;
  res : integer;

function calc(i : integer) : integer;
begin
  if f[i] = -1 then result := 1
  else if d[i] <> -1 then result := d[i]
  else
  begin
    d[i] := calc(f[i]) + 1;
    result := d[i];
  end;
end;

begin
  read(n);
  for i:=1 to n do read(f[i]);
  fillchar(d,sizeof(d),255);
  res := 1;
  for i:=1 to n do res := Max(res, calc(i));
  writeln(res);
end.