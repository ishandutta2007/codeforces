var s0=readline().split(' ')
var n=+s0[0],have=+s0[1];
var s=readline();
var l=-1,h=n-2;
while(l+1<h) {
    var m=l+Math.floor((h-l)/2);
    var at=0; var ok=true; var need=1;
    while(ok&&at<n-1) {
        var to=at+m+1;
        if(to>n-1) to=n-1;
        while(to>at&&s[to]=='1') --to;
        if(to==at) { ok=false; break; }
        ++need; at=to;
    }
    //print(m," -> ",need," (",ok,")");
    if(ok&&need<=have) h=m; else l=m;
}
print(h);