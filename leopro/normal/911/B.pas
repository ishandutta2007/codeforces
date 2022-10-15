program abcd;

uses
  Math;

var
  n, a, b, sum, i: LongInt;

begin
  Read(n);  Read(a);  ReadLn(b);
  For i := 300 downto 0 do
  begin
    sum := (a div i) + (b div i);
    If sum >= n then Break;    
  end;
  If i > min(a, b) then i := min(a, b); 
  WriteLn(i);
end.