program Project1;

uses
  Math;

var
  n, m, a: Int64;

begin
  Read(n); Read(m); ReadLn(a);
  n := ceil(n/a);
  m := ceil(m/a);
  n := n*m;
  WriteLn(n);  
end.