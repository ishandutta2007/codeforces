uses
  Classes, SysUtils, Dialogs;

var
 WhiteCell: array [1..50, 1..50] of Boolean;
 i, j,k,l,  n, m: Int32;
 ans: Boolean;
 c: Char;
 point1, point2, point3: TPoint;

 function ToPoint(x, y: Int32): TPoint;
 begin
   Result.x := x;
   Result.y := y;
 end;

begin
  ReadLn(n, m);
  For i := 1 to n do
  begin
    For j := 1 to m do
    begin
      Read(c);
      If c = '.' then WhiteCell[i, j] := True else WhiteCell[i, j] := False;
    end;
    ReadLn;
  end;
  
  ans := True;
  For i := 1 to n do
  begin
    For j := 1 to m do
    begin
      If not WhiteCell[i, j] then point1 := ToPoint(i, j) else Continue;
      For k := 1 to n do
      begin
        If not WhiteCell[k, point1.y] then point2 := ToPoint(k, point1.y) else Continue;
        For l := 1 to m do
        begin
          If not WhiteCell[point1.x, l] then point3 := ToPoint(point1.x, l) else Continue;
          If WhiteCell[point2.x, point3.y] then  ans := False;
        end;
      end;
    end;
  end;
  If ans then WriteLn('Yes') else WriteLn('No'); 
end.